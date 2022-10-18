#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG

#define mp make_pair
#define it iterator

using namespace std;

typedef pair<char,char> pcc;

int main()
{
    char c[1001];
    scanf("%s",c);
    string s=c;
    scanf("%s",c);
    string t=c;
    int n=s.length();
    set<char> a;
    set<pcc> p;
    for(int i=0;i<n;i++)
    {
        char a1=s[i],a2=t[i];
        pair<char,char> tp=mp(min(a1,a2),max(a1,a2));
        if(!a.count(a1)&&!a.count(a2))
            a.insert(a1),a.insert(a2),p.insert(tp);
        if(!p.count(tp))
            printf("-1\n"),exit(0);
    }
    for(set<pcc>::it i=p.begin();i!=p.end();)
    {
        set<pcc>::it ni=i;
        ni++;
        if(i->first==i->second)
            p.erase(i);
        i=ni;
    }
    printf("%d\n",p.size());
    for(set<pcc>::it i=p.begin();i!=p.end();i++)
        printf("%c %c\n",i->first,i->second);
}