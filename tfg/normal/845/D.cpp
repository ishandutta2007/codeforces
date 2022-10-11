#include <iostream>
#include <stack>

int take = 0;

int main()
{
    int n;
    std::cin >> n;
    int ans = 0;
    std::stack<int> s;
    int cur = 0;
    while(n--)
    {
        int t;
        std::cin >> t;
        if(t == 1)
        {
            //change
            int v;
            std::cin >> v;
            cur = v;
            while(!s.empty() && s.top() < cur)
            {
                ans++;
                s.pop();
            }
        }
        else if(t == 2)
        {
            ans += take;
            take = 0;
        }
        else if(t == 3)
        {
            int v;
            std::cin >> v;
            s.push(v);
            while(!s.empty() && s.top() < cur)
            {
                ans++;
                s.pop();
            }
        }
        else if(t == 4)
        {
            take = 0;
        }
        else if(t == 5)
        {
            while(!s.empty())
                s.pop();
        }
        else
        {
            take++;
        }
    }
    std::cout << ans << "\n";
}