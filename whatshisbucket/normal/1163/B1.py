n=int(input())
u=list(map(int,input().split()))
true=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
big=1
for i in range(n):
    true[u[i]-1]+=1
    vals=set(true)
    try:
        vals.remove(0)
    except:
        pass
    if len(vals)==2 and 1 in vals and true.count(1)==1:
        big=max(big,i+1)
    elif len(vals)==1 and 1 in vals:
        big=max(big,i+1)
    elif len(vals)==1 and true.count(max(vals))==1:
        big=max(big,i+1)
    elif len(vals)==2:
        a=max(vals)
        if true.count(a)==1 and min(vals)==a-1:
            big=max(big,i+1)
print(big)