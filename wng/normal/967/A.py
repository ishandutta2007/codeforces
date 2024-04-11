n,s=[int(k) for k in raw_input().split(" ")]
t=[-s-1]
for i in range(n):
    h,m=[int(k) for k in raw_input().split(" ")]
    t+=[60*h+m]

st=sorted(t)

for i in range(len(t)):
    if i==len(t)-1 or t[i+1]-t[i]-1>=2*s+1:
        ch=t[i]+1+s
        print ch/60,ch%60
        break