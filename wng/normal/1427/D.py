
n=int(input())
d=[int(i) for i in input().split()]


def process(it, tar):
    res=[]
    kk=0
    #print(tar, it)
    assert(sum(tar)==len(it))
    for k in tar:
        res=it[kk:kk+k]+res
        kk+=k
    #print(tar,res,it)
    assert(len(res)==len(it))
    return res


t = list(range(1,n+1))
r=[]
while (d!=t):
    z=[0]*(n+1)
    for i in range(n):
        z[d[i]]=i+1
        if d[i]!=1 and z[d[i]-1]==0:
            j= [k for k in range(n) if d[k]==d[i]-1][0]
            kk=0
            while (i+kk+1<n and d[i+kk+1]==d[i]+kk+1):
                kk+=1
            jj=0
            while (j-jj-1>=0 and d[j-jj-1]==d[j]-jj-1):
                jj+=1
            tar = ([i] if i else []) + [kk+1] + ([n-i-kk-1-jj-1-(n-1-j) +  jj+1]) + ([n-1-j] if j<n-1 else [])
            tar= [k for k in tar if k]
            d=process(d, tar)
            r+=[tar]
            break
    #print(d, i, j)

print(len(r))
for k in r:
    print(len(k), *k)