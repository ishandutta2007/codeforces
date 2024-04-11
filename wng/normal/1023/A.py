n,m=[int(k) for k in raw_input().split(" ")]
s=raw_input()
t=raw_input()

a=s.split("*")

if len(a)==1:
    res="YES" if (s==t) else "NO"
else:
    res="YES" if t[:len(a[0])]==a[0] and ((t[-len(a[1]):]==a[1]) if len(a[1]) else True) and n-1<=m else "NO"

print res