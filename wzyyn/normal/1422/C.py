mo=1000000007
s=input()
v=0
v1,s1=0,0
v2,s2=0,0
for i in range(len(s)):
    c=int(s[i])
    
    v2=(v2*10+v1*10+(s2+s1)*c)%mo;
    s2=s2+s1
    
    v1=(v1+v)%mo
    s1=s1+1
    
    v=(v*10+c)%mo
    # print(i,v,v1,v2,s1,s2)

print((v1+v2)%mo)