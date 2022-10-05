#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 200;
vector<int> g[26];
string now,pre;
int in[26],ans[26];
int tot=0; 
void toposort()
{
    queue<int> que;
    for(int i=0;i<26;i++)  if(!in[i]) que.push(i);
    while(!que.empty()) {
        int x=que.front();
        ans[tot++]=x;
        que.pop();
        for(int i=0;i<g[x].size();i++)
		{
        	in[g[x][i]]--;
            if(!in[g[x][i]])  que.push(g[x][i]);
        }
    }
    if(tot!=26) cout<<"Impossible"<<endl;
    else
	{
        for(int i=0;i<26;i++)
		{
            cout<<char('a'+ans[i]);
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
	{
        cin>>now;
        int len=min(now.length(),pre.length());
        bool ok=false;
        for(int j=0;j<len;j++)
		{
            if(now[j]!=pre[j])
			{
                ok=true;
                g[pre[j]-'a'].push_back(now[j]-'a');
                in[now[j]-'a']++;
                break;
            }
        }
        if(!ok&&now.length()<pre.length())
		{
            cout<<"Impossible"<<endl;
            return 0;
        }
        pre=now;
    }
    toposort();
    return 0;
}