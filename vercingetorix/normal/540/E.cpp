#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

ll  _mergeSort(int arr[], int temp[], int left, int right);
ll merge(int arr[], int temp[], int left, int mid, int right);

ll mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

ll _mergeSort(int arr[], int temp[], int left, int right)
{
    ll mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

ll merge(int arr[], int temp[], int left, int mid, int right)
{
    ll i, j, k;
    ll inv_count = 0;
    
    i = left; /* i is index for left subarray*/
    j = mid;  /* i is index for right subarray*/
    k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            
            inv_count = inv_count + (mid - i);
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    vi a(2*n);
    vi decode(2*n);
    map<int, int> index;
    vpi q;
    int x,y;
    set<int> al;
    vll bef(2*n, 0);
    
    for(int i=0; i<n; i++)  {
        cin>>x>>y;
        al.insert(x);
        al.insert(y);
        q.push_back(mp(x,y));
    }
    int ind=0;
    int prev=0;
    
    for(auto it=al.begin(); it!=al.end(); it++) {
        bef[ind]=*it-prev-1;
        prev=*it;
        index[*it] = ind;
        decode[ind]=*it;
        a[ind]=ind;
        ind++;
    }
    
    for(int i=0; i<n; i++) {
        x=q[i].first;
        y=q[i].second;
        swap(a[index[x]], a[index[y]]);
    }
    
    ll ans=0;
    vi c(ind+1, 0);
    set<int> dob;
    for(int i=0; i<ind; i++) {
        int u=i;
        int v=a[i];
        if(u>v) swap(u,v);
        c[u+1]++;
        c[v+1]--;
        //ans+=dob.lower_bound(v)-dob.begin();
        //dob.insert(v);
    }
    
    int temp[ind];
    for(int i=0; i<ind; i++) temp[i]=a[i];
    
    ans+=mergeSort(temp, ind);
    
    ll curc=0;
    for(int i=0; i<ind; i++) {
        curc+=c[i];
        ans+=curc*bef[i];
    }
    cout<<ans;
}