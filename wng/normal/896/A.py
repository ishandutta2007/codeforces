q=int(raw_input())
#[int(k) for k in raw_input().split(" ")]


f0="What are you doing at the end of the world? Are you busy? Will you save us?"
fn0='What are you doing while sending "'
fn1='"? Are you busy? Will you send "'
fn2='"?'

di=[75]+[0]*(10**5)

dim=10**18

i=1
while i<=10**5:
    di[i]=min(dim,(di[i-1])*2+68)
    i+=1


dr={}


res=""
for i in range(q):
    n,k=[int(kk) for kk in raw_input().split(" ")]
    ok=False
    if k>di[n]:
        res+="."  
    else:
        while not ok:
            if n==0:
                res+=f0[k-1]
                ok=True
            else:
                if k<=34:
                    ok=True
                    res+=fn0[k-1]
                elif k<=di[n-1]+34:
                    n-=1
                    k-=34
                elif k<=66+di[n-1]:
                    ok=True
                    res+=fn1[k-34-di[n-1]-1]
                elif k>66+2*di[n-1]:
                    ok=True
                    res+=fn2[k-66-2*di[n-1]-1]
                else:
                    k-=66+di[n-1]
                    n-=1
#    print res

print res