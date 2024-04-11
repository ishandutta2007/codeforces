n,k=map(int,input().split())
h=list(map(int,input().split()))
tall=max(h)
heights=[0]*tall
for i in range(n):
    heights[h[i]-1]+=1
heights.reverse()
j=[heights[0]]
for i in range(tall-1):
    j.append(j[-1]+heights[i+1])
fin=min(h)
at=0
avail=k
ops=1
while at<tall-fin:
    if j[at]>avail:
        ops+=1
        avail=k-j[at]
        at+=1
    else:
        avail-=j[at]
        at+=1
lame=True
for i in range(len(h)-1):
    if h[i]!=h[i+1]:
        lame=False
        break
if lame:
    print(0)
else:
    print(ops)