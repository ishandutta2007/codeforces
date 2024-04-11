#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
map<long long,int> ma;
map<long long,string> ma2;
int calc(long long x)
{
    int sum=0;
    for (;x!=0;)
    {
        x/=10;
        sum++;
    }
    return sum;
}
string get_string(long long x)
{
    string t="";
    for (;x!=0;)
    {
        t=(char)((x%10)+'0')+t;
        x/=10;
    }
    return t;
}
string t[100005];
int tt[100005];
map<long long,int> ma3;
map<long long,string> ma4;
int get_val(long long x)
{
    if (ma3.find(x)!=ma3.end()) return ma3[x];
    return calc(x);
}
string get_val2(long long x)
{
    if (ma4.find(x)!=ma4.end()) return ma4[x];
    if (x<=100000) return t[x];
    return get_string(x);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=1;i<=100000;i++)
    {
        t[i]=get_string(i);
    }
    for (i=1;i<=100000;i++)
    {
        tt[i]=calc(i);
    }
    for (i=2;i<=100000;i++)
    {
        long long p=1;
        int j;
        for (j=1;;j++)
        {
            p*=i;
            if (p>10000000000ll) break;
            if (j==1) continue;
            if (calc(i)+calc(j)+1>=calc(p)) continue;
            if (p>=1000)
            {
                int ans=1000;
                if (ma.find(p)!=ma.end())
                {
                    ans=ma[p];
                }
                if (calc(i)+1+calc(j)<ans)
                {
                    ma[p]=tt[i]+1+tt[j];
                    ma2[p]=t[i]+"^"+t[j];
                }
            }
        }
    }
    //cout<<ma.size()<<endl;
    //a^b+c
    //a^b*c+d
    //a^b+c^d
    //a^b*c+d^e
    map<long long,int>::iterator ii;
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        ma3.insert(*ii);
        ma4[(*ii).first]=ma2[(*ii).first];
    }
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        int i;
        if ((*ii).second>3) continue;
        for (i=1;i<=9;i++)
        {
            int now=(*ii).first+i;
            if (calc(now)<=5) continue;
            ma3[now]=5;
            ma4[now]=ma2[(*ii).first]+"+"+(char)(i+'0');
        }
    }
    long long n;
    cin>>n;
    int min_ans=calc(n);
    string min_string=get_string(n);
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        if (n<(*ii).first) break;
        long long t=n-(*ii).first;
        int val;
        if (ma3.find(t)==ma3.end())
        {
            if (t>=1000000) continue;
        }
        else
        {
            if (ma3[t]>=6) continue;
        }
        string val2;
        if (n==(*ii).first)
        {
            val=(*ii).second;
            val2=ma2[(*ii).first];
        }
        else
        {
            val=(*ii).second+1+get_val(n-(*ii).first);
            val2=ma2[(*ii).first]+"+"+get_val2(n-(*ii).first);
        }
        if (val<min_ans)
        {
            min_ans=val;
            min_string=val2;
        }
    }
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        if (n<(*ii).first) break;
        int t=n/(*ii).first;
        if (t==1) continue;
        if (t>=100000) continue;
        long long p=n%(*ii).first;
        if (((ma.find(p)!=ma.end())&&(ma[p]<=3))||(p<1000))
        {
            int val;
            string val2;
            if (p==0)
            {
                val=(*ii).second+1+get_val(t);
                if (val>=min_ans) continue;
                val2=ma2[(*ii).first]+"*"+get_val2(t);
            }
            else
            {
                val=(*ii).second+1+get_val(t)+1+get_val(p);
                if (val>=min_ans) continue;
                val2=ma2[(*ii).first]+"*"+get_val2(t)+"+"+get_val2(p);
            }
            if (val<min_ans)
            {
                min_ans=val;
                min_string=val2;
            }
        }
    }
    cout<<min_string<<endl;
    return 0;
}