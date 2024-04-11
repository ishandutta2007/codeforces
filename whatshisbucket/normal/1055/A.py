n,s=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if a[0]==0:
    print("NO")
else:
    if a[s-1]==1:
        print("YES")
    else:
        if b[s-1]==0:
            print("NO")
        else:
            done=False
            for i in range(s,n):
                if a[i]==b[i]==1:
                    print("YES")
                    done=True
                    break
            if not done:
                print("NO")