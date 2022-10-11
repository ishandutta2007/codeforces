#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> ii; 
typedef long long int ll;
 
ll i_w[550];
ll k;
 
ll d_w[550];
 
int n;
 
int main()
{
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        std::cin >> i_w[i];
    }
    std::cin >> k;
    for(int i=0;i<k;i++)
    {
        std::cin >> d_w[i];
    }
    int left=-1;
    int right;
    bool valid=true;
    std::queue<ii> q;
    std::queue<ii> domi;
    for(int i=0;i<k && valid;i++)
    {
        //std::cout << "getting wanted #" << i << std::endl;

        left++;
        if(left==n)
        {
            valid=false;
            break;
        }
        ll c_sum=0;
        right=left;
        int ind_m=0;
        ll max_w=0;
        int type_dom=0;
        while(c_sum<d_w[i] && right<n)
        {
            c_sum+=i_w[right];
            bool can_next=(c_sum<d_w[i] && right+1<n);
            bool can_left=(right!=left && i_w[right]>i_w[right-1]);
            bool can_right=(can_next && i_w[right]>i_w[right+1]);
            int cur_type=(can_left?1:0)+(can_right?2:0);
            if(i_w[right]>max_w && cur_type)
            {
                max_w=i_w[right];
                type_dom=cur_type;
                ind_m=right;
            }
            right++;
        }
        right--;
        //std::cout << "interval is " << left << ',' << right << " dominating is " << ind_m << std::endl;
        if(c_sum!=d_w[i])
            valid=false;
        if(max_w==0 && (right-left!=0))
            valid=false;
        q.push(ii(left,right));
        domi.push(ii(ind_m,type_dom));
        left=right;
    }
    if(right!=n-1)
        valid=false;
    if(!valid)
    {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    int offset=1;
    while(!q.empty())
    {
        ii inter=q.front();
        ii c_type=domi.front();
        q.pop();
        domi.pop();
        if(c_type.second==0)
        {
            offset++;
            continue;
        }
        left=c_type.first-inter.first;
        right=inter.second-c_type.first;
        int cur_off=offset+c_type.first-inter.first;
        if(c_type.second&1)
        {
            while(left)
            {
                std::cout << cur_off << " L\n";
                left--;
                cur_off--;
            }
            while(right)
            {
                std::cout << cur_off << " R\n";
                right--;
            }
        }
        else
        {
            while(right)
            {
                std::cout << cur_off << " R\n";
                right--;
            }
            while(left)
            {
                std::cout << cur_off << " L\n";
                left--;
                cur_off--;
            }
        }
        offset++;
    }

}