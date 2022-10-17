n=input()
s=sorted([raw_input() for _ in range(n)])
d=raw_input()
n/=2
l=sum(map(len,s))/n
z=[]
for i in range(n):
    x=s.pop(0)
    for y in s:
        if len(x+y)==l:
                z.append(min(x+d+y,y+d+x))
                s.remove(y)
                break
print '\n'.join(sorted(z))