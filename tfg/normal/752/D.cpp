#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>

int n, k;
int even_ans=0;

const int eps='z'-'a'+2;

class node
{
public:
	node()
	{
		for(int i=0;i<eps;i++)
			to[i]=-1;
	}

	int add(int val)
	{
		int ans;
		if(used.empty() || val<used.top())
		{
			max_val.push(val);
			ans=0;
		}
		else
		{
			ans=val-used.top();
			max_val.push(used.top());
			used.pop();
			used.push(val);
		}
		even_ans+=ans;
		return ans;
	}

	bool present()
	{
		return !max_val.empty();
	}

	void use()
	{
		even_ans+=max_val.top();
		used.push(max_val.top());
		max_val.pop();
	}

	int to[eps];
	std::priority_queue<int> max_val;
	std::priority_queue<int, std::vector<int>, std::greater<int> > used;

};

std::string str;
int cur_val;

node Trie[100100];
int cur_size;

void init()
{
	Trie[0]=node();
	cur_size=1;
}

int on;

int reverse_go()
{
	on=0;
	//std::cout << "Going backwards on " << str << '\n';
	for(int i=n-1;i>=0;i--)
	{
		int to=Trie[on].to[str[i]-'a'];
		if(to==-1)
			return 0;
		on=to;
		//std::cout << "on: " << on << '\n'; 
	}
	if(Trie[on].present())
	{
		int cur_ans=cur_val + Trie[on].max_val.top();
		//std::cout << "could get, val is " << cur_ans << ", on is " << on << '\n';
		if(cur_ans<=0)
			return 0;
		Trie[on].use();
		return cur_ans;
	}
	else
		return 0;
}

int add_string(bool use)
{
	on=0;
	//std::cout << "Adding " << str << " to trie\n";
	for(int i=0;i<n;i++)
	{
		int to=Trie[on].to[str[i]-'a'];
		if(to==-1)
		{
			to=cur_size;
			Trie[cur_size++]=node();
			Trie[on].to[str[i]-'a']=to;
		}
		on=to;
		//std::cout << "on: " << on << '\n';
	}
	int ans=Trie[on].add(cur_val);
	if(use)
	{
		Trie[on].use();
		return 0;
	}
	return ans;
}

std::pair<int, std::string> a[100100];

int main()
{
	std::cin >> k >> n;
	int ans=0;
	init();

	for(int i=0;i<k;i++)
		std::cin >> a[i].second >> a[i].first;

	std::sort(a,a+k,std::greater<std::pair<int, std::string> >());
	
	std::set<int> pal;
	for(int i=0;i<k;i++)
	{
		//std::cin >> str >> cur_val;
		str=a[i].second;
		cur_val=a[i].first;
		int left=0;
		int right=n-1;
		bool can_alone=true;
		while(left<right)
		{
			if(str[left++]!=str[right--])
				can_alone=false;
		}
		int cur_ans=reverse_go();
		bool use=cur_ans>0;
		cur_ans+=add_string(use);
		//std::cout << "cur ans is " << cur_ans << '\n';
		//even_ans+=cur_ans;
		if(can_alone)
			pal.insert(on);
	}
	std::set<int>::iterator it=pal.begin();
	const int INF=0x3f3f3f3f;
	int min_pal=INF;
	int max_pal=-INF;
	while(it!=pal.end())
	{
		on=(*it);
		if(!Trie[on].used.empty())
			min_pal=std::min(min_pal, Trie[on].used.top());
		if(!Trie[on].max_val.empty())
			max_pal=std::max(max_pal, Trie[on].max_val.top());
		it++;
	}
	ans=even_ans;
	//std::cout << "ans is " << ans << '\n';
	if(min_pal!=INF)
		ans=std::max(ans, even_ans-min_pal);
	//std::cout << "ans is " << ans << '\n';
	if(max_pal!=-INF)
		ans=std::max(ans, even_ans+max_pal);
	//std::cout << "ans is " << ans << '\n';
	std::cout << ans << '\n';
}