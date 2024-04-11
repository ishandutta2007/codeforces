#include<bits/stdc++.h>

using namespace std;

struct vertex ///   
{
    vertex* next[27]; ///     
    vertex* p; ///  
    int cnt; /// -  
    bool one; ///         
};

vertex* root; ///   

bool eng(char c) /// c -   
{
    return c>='a'&&c<=('z'+1);
}

void add(char* s) ///     
{
    vertex* v = root;
    bool del=false;
    for (; eng(*s); s++)
    {
        char c = (*s)-'a';
        if (v->next[c] == NULL)
        {
            v->cnt++;
            v->next[c]=new vertex;
            memset(v->next[c]->next, 0, sizeof(v->next[c]->next));
            v->next[c]->p=v;
            v->next[c]->cnt=0;
            v->next[c]->one=true;
            if(!del)
                {
                    del=true;
                    for(vertex*v1=v;v1!=NULL;v1=v1->p)
                        v1->one=false;
                }
        }
        v = v->next[c];
    }
    if(!(v->cnt))
        for(;v!=NULL&&v->cnt<=1&&v->one;v=v->p);
    for(;v!=NULL;v=v->p)
        v->one=false;
}

const int INF=1e9;

int pref(char* s) ///  
{
    vertex* v = root;
    int res=0;
    for (;v!=NULL;s++)
    {
        char c = (*s)-'a';
        if(v->cnt&&!eng(*s))
            return -INF;
        if(v->one&&(v->cnt==0||v->next[c]))
            res++;
        if(!eng(*s))
            break;
        if(v->cnt&&v->next[c]==NULL)
            return -INF;
        v=v->next[c];
    }
    return res-1;
}

int len(char* s) ///  
{
    for (int res=0;;s++,res++)
        if(!eng(*s))
            return res;
}

void print(vertex* v=root,int c=-1,int h=0)
{
    if(v==root)
        printf("==PRINT==\n");
    for(int i=0;i<h;i++)
        printf(" ");
    if(c==-1)
        c=' ';
    else
        c+='a';
    printf("'%c' cnt=%d one=%d\n",c,v->cnt,v->one);
    for(int i=0;i<27;i++)
        if(v->next[i])
            print(v->next[i],i,h+1);
    if(v==root)
        printf("===END===\n");
}

const int N=3e5+10; ///   

char s[N]; ///  

int main1()
{
    //freopen("input.txt","r",stdin);
    int ans=0; /// 
    root=new vertex;
    root->one=true;
    memset(root->next, 0, sizeof(root->next));
    root->p=NULL;
    root->cnt=0;
    s[0]='z'+1;
    add(s);
    while(gets(s))
    {
        char* c=s;
        while(true)
        {
            while(!eng(*c))
                if(!(*c))
                    break;
                else
                    /*cout<<"("<<(*c)<<")",*/ans++,c++;
            //cout<<"\n";
            if(!*c)
                break;
            //print();
            int p=pref(c),l=len(c);
            ans+=min(l-p+1,l);
            add(c);
            while(eng(*c))
                /*cout<<(*c),*/c++;
            //cout<<" -> "<<(p==-INF?-10:p)<<" "<<l<<" -> "<<min(l-p+1,l)<<"\n";
        }
        ans++;
    }
    cout<<ans<<"\n";
    //print();
}

int main()
{
    main1();
}