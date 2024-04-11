#include<iostream>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 1000007;

struct KMP
{
    int nxt[maxn];
    void getNext(string t)
    {
        memset(nxt,-1,sizeof(nxt));
        int i=0,j=-1;
        while(i<t.size())
        {
            if(j==-1||t[i]==t[j]) i++,j++,nxt[i]=j;
            else j=nxt[j];
        }
    }
    int work(string s,string t)
    {
        getNext(t);
        int i=0,j=0,lens=s.size(),lent=t.size();
        while(i<lens&&j<lent)
        {
            if(j==-1||s[i]==t[j]) i++,j++;
            else j=nxt[j];
        }
        if(j==t.size()) return i-j;
        else return -1;
    }
};
int pmt[maxn],pmtbug[maxn],nxt2[maxn];
int main()
{
    ios::sync_with_stdio(0);
    string t;cin>>t;
    if(t.size()<=2)
    {
        cout <<"Just a legend\n";
        return 0;
    }
    int sz = t.size();
    string s = t.substr(1,sz-2);
    nxt2[0] = -1;
    int i=0,j=-1;
    while(i<t.size())
    {
        if(j==-1||t[i]==t[j]) i++,j++,nxt2[i]=j;
        else j=nxt2[j];
    }
    for(int j=0;j<t.size();++j) pmt[j]=nxt2[j+1];
    pmtbug[0] = 0;
    i=1,j=0;
    while(i<t.size())
    {
        if(t[i]==t[j]) pmtbug[i]=j+1,i++,j++;
        else if(j==0) pmtbug[i]=0,i++;
        else j=pmtbug[j-1];
    }
    for(int j=0;j<t.size();++j)
    {
        if(pmt[j]!=pmtbug[j])
        {
            cout << j << " " << pmt[j] << " " << pmtbug[j] << endl;
            if(j>100) for(int k=0;k<=j;++k) cout<<s[k]<<endl;
            else for(int k=0;k<=j;++k) cout<<s[k];
            return 0;
        }
    }
    KMP kmp;
    int len = pmt[t.size()-1];
    while(len)
    {
        string t2 = t.substr(0,len);
        int idx = kmp.work(s,t2);
        if(idx!=-1) {cout << t2 << endl;break;}
        else len = pmt[len-1];
    }
    if(!len) cout <<"Just a legend\n";
}