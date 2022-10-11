#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int b[1000100];
int used[1000100];
std::vector<int> mat[1000100];
bool p[1000100];
std::vector<int> tests;

int n,m;

int INF = 9999999;


typedef std::pair<int, int> ii;

int main()
{
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int temp;
		std::cin >> temp;
		tests.push_back(temp);
		if(temp!=0)
		{
			mat[temp].push_back(i);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		std::cin >> b[i];
		mat[i].push_back(INF);
	}
		
	int cur_day=0;
	int study=0;
	int done=0;
	std::priority_queue<int,std::vector<int>,std::greater<int> > hp; 
	while(done!=m && cur_day<n)
	{	
		if(tests[cur_day]==0)
		{
			cur_day++;
			continue;
		}
		int now_m=tests[cur_day];
		int need=b[now_m];
		if(p[now_m])
		{
			cur_day++;
			continue;
		}

		//std::cout << "on day " << cur_day << " mat " << now_m << " needing " << need << std::endl;
		//std::cout << "study time is " << study << " done is " << done << std::endl;
		if(mat[now_m][used[now_m]]>cur_day){cur_day++;continue;}
		while(mat[now_m][used[now_m]]<cur_day) used[now_m]++;

		
		if(cur_day<need) {cur_day++;continue;}
		if(mat[now_m][used[now_m]]==INF)
		{
			done=0;
			break;
		}
		int next=mat[now_m][used[now_m]+1];
		
		while(!hp.empty() && hp.top()<next && cur_day-study-done<need)
		{
			int test_m=tests[hp.top()];
			if(test_m==now_m || mat[test_m][used[test_m]]>=hp.top())
			{
				hp.pop();
				continue;
			}

			if(p[test_m] && mat[test_m][used[test_m]]<cur_day && hp.top()>cur_day) 
			{
				//if(n==100000 && m==5)
				//	std::cout << "postponing " << test_m << " from " << mat[test_m][used[test_m]] << " until " << hp.top() << std::endl;
				p[test_m]=false;
				study-=b[test_m];
				done--;
			}
			used[test_m]++;
			hp.pop();
			if(mat[test_m][used[test_m]] == INF)
				std::cout << "pushing inf\n";
			hp.push(mat[test_m][used[test_m]+1]);

		}
		//std::cout << "on day " << cur_day << " mat " << now_m << " needing " << need << std::endl;
		//std::cout << "study time is " << study << " done is " << done << std::endl;

		if(cur_day-study-done>=need)
		{
			//if(n==100000 && m==5)
			//std::cout << "could complete " << now_m << " on day " << cur_day << std::endl;
			p[now_m]=true;
			done++;
			study+=b[now_m];
			hp.push(next);
		}
		cur_day++;
	}
	if(done==m)
		std::cout << cur_day << std::endl;
	else
		std::cout << -1 << std::endl;
		
}