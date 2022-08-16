n,m = map(int,input().split())
if m >= n:
    print(n)
else:
    ans = m
    pos = -1
    low = 0
    high = 10**12
    n -= m
    while low <= high:
        mid  = (low+high)//2
        # print(mid,(mid*(mid+1))//2)
        if (mid*(mid+1))//2 >= n:
            pos = mid
            high = mid-1
        else:
            low = mid+1
    print(ans+pos)