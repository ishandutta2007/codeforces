#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=300050;
struct AhoCorascik
{
    struct Node
    {
    	map<char,int> go;
    	int link,val;
    	Node(int a=0, int b=0){ link=a;val=b;}
    };
    vector<Node> node;
    int root;
    int AddNode(int a=0, int b=0){ node.pb(Node(a,b));return node.size()-1;}
    void Clear(){ root=0;node.clear();}
    void init(){ root=AddNode();}
    void Add(string s)
    {
    	int cur=root;
    	for(int i=0;i<s.size();i++)
		{
            if(!node[cur].go.count(s[i]))
				node[cur].go[s[i]]=AddNode();
			cur=node[cur].go[s[i]];
		}
		node[cur].val++;
    }
    void Build()
    {
		queue<int> q;
		for(auto p:node[root].go)
		{
			q.push(p.second);
			node[p.second].link=root;
		}
		for(int i=0;i<26;i++)
		{
			if(!node[root].go.count('a'+i))
				node[root].go['a'+i]=root;
		}
		while(q.size())
		{
			int x=q.front();
			q.pop();
			for(auto p:node[x].go)
			{
				int link=node[x].link;
				while(!node[link].go.count(p.first)) link=node[link].link;
				node[p.second].link=node[link].go[p.first];
				node[p.second].val+=node[node[p.second].link].val;
				q.push(p.second);
			}
		}
    }
    int Count(string s)
    {
    	int cur=root;
    	int ans=0;
    	for(int i=0;i<s.size();i++)
		{
            while(!node[cur].go.count(s[i])) cur=node[cur].link;
			cur=node[cur].go[s[i]];
			ans+=node[cur].val;
		}
		return ans;
    }
};
struct BinomialHeapTrick
{
	vector<string> all;
	AhoCorascik AC[19];
	BinomialHeapTrick(){}
	void Add(string s)
	{
		all.pb(s);
		int sz=all.size();
		int i;
		for(i=0;i<19 && !((sz>>i)&1);i++) AC[i].Clear();
		AC[i].Clear();
		AC[i].init();
		int work=1<<i;
		for(int j=1;j<=work;j++) AC[i].Add(all[sz-j]);
		AC[i].Build();
	}
	int Count(string t)
	{
		int sz=all.size(),ans=0;
		for(int i=0;i<19;i++) if((sz>>i)&1)
		{
			ans+=AC[i].Count(t);
		}
		return ans;
	}
} ADD,SUB;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	int q,i,ty;
	string t;
	cin>>q;
	while(q--)
	{
		cin>>ty>>t;
		if(ty==1) ADD.Add(t);
		if(ty==2) SUB.Add(t);
		if(ty==3) cout<<ADD.Count(t)-SUB.Count(t)<<endl;
	}
	return 0;
}