#include<bits/stdc++.h>

using namespace std;

int n,m,head=0,tail=1;
bool used[20001];
pair<int,int> q[20001];

void add(int f,int s)
{
    if((f<0)||(f>max(n,m*2))||(used[f]))
        return;
    //cout<<f<<' '<<s;
    if(f==m)
    {
        cout<<s;
        exit(0);
    }
    q[tail]=make_pair(f,s);
    used[f]=true;
    tail=(tail+1)%20001;
    //cout<<" OK\n";
}

int main ()
{
    cin>>n>>m;
    q[0]=make_pair(n,0);
    if(n==m)
        add(m,0);
    while(true)
    {
        //cout<<q[head].first<<' '<<q[head].second<<endl;
        add(q[head].first*2,q[head].second+1);
        add(q[head].first-1,q[head].second+1);
        head=(head+1)%20001;
    }
}