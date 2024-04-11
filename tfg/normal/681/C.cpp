#include <iostream>
#include <queue>

struct qry
{
	qry(int t = 0, int n = 0){type = t, num = n;}
	int type, num;

	void print()
	{
		if(type == 0)
			std::cout << "insert " << num << '\n';
		else if(type == 1)
			std::cout << "getMin " << num << '\n';
		else
			std::cout << "removeMin\n";
	}

	void read()
	{
		std::string str;
		std::cin >> str;
		if(str[0] == 'r')
		{
			type = 2;
			return;
		}
		std::cin >> num;
		if(str[0] == 'i')
			type = 0;
		else
			type = 1;
	}
};



int main()
{
	int n;
	while(std::cin >> n)
	{
		std::vector<qry> qries;
		for(int i = 0; i < n; i++)
		{
			qry hmm;
			hmm.read();
			qries.push_back(hmm);
		}
		std::vector<qry> ans;
		std::priority_queue<int, std::vector<int>, std::greater<int> > hp;
		for(int i = 0; i < n; i++)
		{
			qry cur = qries[i];
			//std::cout << "on qry:";cur.print();
			if(cur.type == 0)
				hp.push(cur.num);
			else if(cur.type == 2)
			{
				if(hp.empty())
					ans.push_back(qry(0, 1));
				else
					hp.pop();
			}
			else
			{
				while(!hp.empty() && hp.top() < cur.num)
				{
					ans.push_back(qry(2, 0));
					hp.pop();
				}
				if(hp.empty() || hp.top() > cur.num)
				{
					ans.push_back(qry(0, cur.num));
					hp.push(cur.num);
				}
			}

			ans.push_back(cur);
		}
		std::cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++)
			ans[i].print();
	}
}