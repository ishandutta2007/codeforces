#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int a[N];

void rot1(int&x,int&y,int&z)
{
    tie(x,y,z)=make_tuple(z,x,y);
}

void rot2(int ind)
{
    rot1(a[ind],a[ind+1],a[ind+2]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> pos;
        int pos1=0,pos2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(pos.count(a[i]))
                pos1=pos[a[i]],
                pos2=i;
            pos[a[i]]=i;
            a[i]*=N;
            a[i]+=i;
        }
        bool even=true;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[i]>a[j])
                    even=!even;
        if(!even)
            if(pos1)
                swap(a[pos1],a[pos2]);
            else
            {
                cout<<-1<<"\n";
                continue;
            }
        vector<int> idx;
        #define rot(ind) rot2(ind),idx.push_back(ind)
        while(true)
        {
            int i=1;
            while(i<=n&&min_element(a+i,a+n+1)==a+i)
                i++;
            if(i>n-2)
                break;
            int j=min_element(a+i,a+n+1)-a;
            while(j-i>=2)
                rot(j-2),
                j-=2;
            if(j-i==1)
                rot(i),rot(i);
        }
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<"\n";
        if(is_sorted(a+1,a+n+1))
        {
            cout<<idx.size()<<"\n";
            for(int i:idx)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
}