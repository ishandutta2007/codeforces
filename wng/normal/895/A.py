#
n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]


end=n-1
start=n-1

curr=a[n-1]
mm=abs(360-2*curr)

while end>=0:
    while curr<180:
        start=start-1
        curr+=a[start]
        mm=min(mm,abs(2*curr-360))        
    curr-=a[end]
    end-=1        
    mm=min(mm,abs(2*curr-360))    
    
print mm