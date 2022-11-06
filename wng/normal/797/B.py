n=int(raw_input())      
s=[int(k) for k in raw_input().split(" ")]

hs=-10**10
hrse=-10**10
hrso=-10**10
for k in range(n):
    ss=s[k]
    if ss%2==0:
        hrse=max(hrse,max(hrse+ss,ss))
        hrso=max(hrso+ss,hrso) 
    else:
        nhrse=max(hrso+ss,hrse) 
        hrso=max(hrso,max(hrse+ss,ss))
        hrse=nhrse
    hs=max(hs,hrso)
 #   print k,ss,hrse,hrso,hs

print hs