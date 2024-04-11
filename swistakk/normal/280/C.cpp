#include <iostream>
#include <vector>
#include <cstdio>
#define N 100005
using namespace std;
struct wektor
{
	int roz;
	int *tab;
	int roztab;
	wektor()
	{
		tab=new int[1];
		roz=0;
		roztab=1;
	}
	~wektor()
	{
        delete[] tab;
    }
	int size()
	{
		return roz;
	}
	bool empty()
	{
		return roz==0;
	}
	void pop_back()
	{
		roz--;
	}
	int& operator[](int ind)
	{
		return tab[ind];
	}
	int operator[](int ind) const {
        return tab[ind];   
    }
	int back()
	{
		return tab[roz-1];
	}
	void resize(int cos)
	{
		if(cos>roztab)
		{
            int *tmp;
            tmp=new int[2*cos];
            for(int i=0; i<roz; i++)
            {
                tmp[i]=tab[i];
            }
            delete[] tab;
            tab=tmp;
            roztab=2*cos;
        }
        else
        {
            if(cos<roz)
            {
                roz=cos;
            }
        }
    }
	void push_back(int elem)
	{
		resize(roz+1);
		tab[roz]=elem;
		roz=roz+1;;
	}
};
wektor slo[N];
int vis[N];
int gleb[N];
double wynik;
void dfs(int v, int g)
{
    //cout<<v<<endl;
    wynik+=double(1)/g;
    vis[v]=1;
    for(int i=0; i<slo[v].size(); i++)
    {
        int aktv=slo[v][i];
        if(vis[aktv]==0)
        {
            dfs(aktv, g+1);
        }
    }
} 
int main()
{
    // ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    dfs(1, 1);
    printf("%.7lf\n", wynik); //cout<<wynik<<endl;
    return 0;
}