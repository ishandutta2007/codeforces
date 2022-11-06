#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from sys import stdout


n=int(input())

l=1
r=n+1
inf=n+5
a=[None]*(n+2)
a[0]=inf
a[n+1]=inf

def geta(i):
    global a
    if a[i] is None:
        print(f"? {i}")
        stdout.flush()
        a[i]=int(input())
    return a[i]

def ismv(i):
    return (geta(i-1),geta(i),geta(i+1))

while (r-l>1):
    mid=(r+l)//2
    mvs=ismv(mid)
    if mvs[1]==min(mvs):
        r=mid+1
        l=mid
    elif mvs[0]==min(mvs):
        r=mid
    else:
        l=mid+1
print(f"! {l}")
stdout.flush()