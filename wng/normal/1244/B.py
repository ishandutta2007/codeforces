t=[int(k) for k in input().split(" ")][0]
for nt in range(t):
    n=[int(k) for k in input().split(" ")][0]
    a=[int(k) for k in input()]
    mx=n
    for i in range(n):
        if a[i]:
            mx=max(mx,2*(i+1),2*(n-i))
    print(mx)