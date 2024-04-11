n,m=[int(k) for k in raw_input().split(" ")]
import sys
truth=[None]*m

for i in range(m):
    print 1
    sys.stdout.flush()
    rep=int(raw_input())
    if not rep:
        sys.exit(0)
    if rep==-1:
        truth[i]=False
    else:
        truth[i]=True

sta=2
end=n
j=m
while True:
    mid=(sta+end)/2
    print mid
    sys.stdout.flush()
    rep=int(raw_input())
    if not truth[j%m]:
        rep*=-1
    if not rep:
        break
    if rep==1:
        sta=mid+1
    elif rep==-1:
        end=mid-1
    else:
        break
    j+=1