s=raw_input()
t,r=0,0
for i in range(5,len(s)+1):
    t+=(s[i-5:i]=='heavy')
    r+=t*(s[i-5:i]=='metal')
print r