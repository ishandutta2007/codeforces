t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    if n>32:
        print("YES",n-1)
    else:
        max_splits=(4**n-1)//3
        if k>max_splits or (n,k)==(2,3):
            print("NO")
        else:
            done=False
            for i in range(n):
                if k<2**(i+2)-i-3:
                    print("YES",n-i)
                    done=True
                    break
            if not done:
                print("YES",0)