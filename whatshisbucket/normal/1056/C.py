def power(bob):
    return p[bob-1]
n,m=map(int,input().split())
p=list(map(int,input().split()))
x=[0]*(2*n)
pairs=[]
for i in range(m):
    a,b=map(int,input().split())
    x[a-1]=b
    x[b-1]=a
    pairs.append((abs(p[a-1]-p[b-1]),a,b))
pairs.sort(reverse=True)
available=[i+1 for i in range(2*n)]
available.sort(key=power,reverse=True)
t=int(input())
forced=0
for i in range(2*n):
    if t==1:
        if forced>0 and forced in available:
            print(forced)
            available.remove(forced)
            try:
                pairs.remove((abs(power(f)-power(forced)),f,forced))
            except:
                pass
            try:
                pairs.remove((abs(power(f)-power(forced)),forced,f))
            except:
                pass
        elif len(pairs)>0:
            pair=pairs.pop(0)
            if power(pair[1])>power(pair[2]):
                print(pair[1])
                available.remove(pair[1])
            else:
                print(pair[2])
                available.remove(pair[2])
        else:
            guy=available.pop(0)
            print(guy)
        t=2
    else:
        f=int(input())
        available.remove(f)
        if x[f-1]>0:
            forced=x[f-1]
            used=f
        else:
            forced=0
        t=1