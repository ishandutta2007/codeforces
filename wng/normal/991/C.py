n=int(raw_input())

def nbmange(k):
    r=0
    l=n
    while l>0:
        m=min(l,k)
        r+=m
        l-=m
        l-=l/10
    return r
    

    
km=1<<65
tt=0
while km:
    if nbmange(tt+km)*2<n:
        tt+=km
    km>>=1
print tt+1