n=[k for k in raw_input().split(" ")][0]


def sd(n):
    res=0
    while n:
        res+=n%10
        n/=10
    return res

fn=int(n[0])-1
res=str(fn)+"9"*(len(n)-1)
res=int(res)
n=int(n)
print sd(res)+sd(n-res)