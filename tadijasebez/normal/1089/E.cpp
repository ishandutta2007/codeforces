#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
int i=0,j=0;
int cnt=0;
void print()
{
    printf("%c%i ",j+'a',i+1);
    cnt++;
}
bool move()
{
    if(i%2==0)
    {
        j++;
        if(j==6)
        {
            j=5;
            i++;
        }
    }
    else
    {
        j--;
        if(j==-1)
        {
            j=0;
            i++;
        }
    }
    print();
    if(i<7)
        return false;
    return true;
}
int main()
{
    int start;
	int n;
	scanf("%i",&n);
	start=n;
	string s="a1 b1 c1 d1 e1 f1 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 f6 e6 d6 c6 b6 a6 a7 b7 c7 d7 e7 f7 f8 e8 d8 c8 b8 g8 g7 h7 h8";
	if(n==50)
    {
        cout << s;
        return 0;
    }
	print();
	while(n)
    {
        if(n==2)
        {
            j=7;
            print();
            i=7;
            print();
            assert(cnt==start+1);
            return 0;
        }
        n--;
        if(move())
        {
            break;
        }
    }
    while(n)
    {
        if(n==1)
        {
            j=7;
            print();
            assert(cnt==start+1);
            return 0;
        }
        n--;
        j--;
        if(j==-1)
        {
            j=6;
            print();
            break;
        }
        print();
    }
    if(n==1)
    {
        j=7;
        print();
        assert(cnt==start+1);
        return 0;
    }
    else
    {
        i--;
        print();
        n--;
    }
    //printf("%i\n",n);
    while(n)
    {
        if(n==2)
        {
            j++;
            print();
            i=7;
            print();
            assert(cnt==start+1);
            return 0;
        }
        n--;
        i--;
        if(i==-1)
        {
            j=7;
            i=0;
            print();
            break;
        }
        print();
    }
    while(n)
    {
        if(n==1)
        {
            i=7;
            print();
            assert(cnt==start+1);
            return 0;
        }
        n--;
        i++;
        print();
    }
    assert(0);
    return 0;
}