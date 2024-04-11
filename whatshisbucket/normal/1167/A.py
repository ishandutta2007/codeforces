t=int(input())
for u in range(t):
    n=int(input())
    a=input()
    if n>=11:
        if "8" in a[:-10]:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")