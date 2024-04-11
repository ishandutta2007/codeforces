#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
vector<vector<int>> g,h;
vector<int> tin, tout, clr;
vector<vector<int>> sum(2);
int T;
int flip;
int cnt;
bool isp(int v,int u)
{
    return tin[v]<=tin[u]&&tout[v]>=tout[u];
}

void init(int v)
{
    tin[v]=T++;
    for (int u : g[v])
	{
        if(clr[u] == -1)
		{
            clr[u] = clr[v] ^ 1;
            h[v].push_back(u);
            init(u);
        }
        else if(tin[u] < tin[v])
		{
            int dif = clr[v] ^ clr[u];
            if (!dif)
			{
                flip = clr[v] ^ 1;
                ++cnt;
            }
            --sum[dif][u];
            ++sum[dif][v]; 
        }
    }
    tout[v] = T;
}
int sv;
void dfs(int v)
{
    for (int u : h[v])
	{
        dfs(u);
        if (sum[0][u] == cnt && sum[1][u] == 1)
		{
            sv = u;
            flip = clr[v] ^ 1;
        }
        for(int i=0;i<2;i++)sum[i][v] += sum[i][u];
    }
}

int main()
{
    int t;
    t=read();
    for(int greg=1;greg<=t;greg++)
	{
        int n,m;
        n=read();
        m=read();
        g.assign(n, vector<int>());
        h.assign(n, vector<int>());
        for(int i=1;i<=m;i++)
		{
            int v,u;
            u=read();
            v=read();
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        tin.resize(n);
        tout.resize(n);
        for(int i=0;i<2;i++)sum[i].assign(n, 0);
        clr.assign(n, -1);
        cnt = 0;
        T = 0;
        clr[0] = 0;
        init(0);
        if(cnt <= 1)
		{
            printf("YES\n");
            for(int v=0;v<n;v++)printf("%d",clr[v]^flip);
            printf("\n");
            continue;
        }
        sv=-1;
        dfs(0);
        if (sv == -1)
		{
            printf("NO\n");
        }
        else
		{
            printf("YES\n");
            for(int v=0;v<n;v++)printf("%d",clr[v]^isp(sv, v)^flip);
            printf("\n");
        }
    }
    return 0;
}