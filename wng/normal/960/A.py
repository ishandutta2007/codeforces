s=raw_input()

a=0
b=0
c=0
k=0

while k<len(s) and s[k]=='a':
    a+=1
    k+=1
    
while k<len(s) and s[k]=='b':
    b+=1
    k+=1
    
while k<len(s) and s[k]=='c':
    c+=1
    k+=1

if a and b and (c==a or c==b) and k==len(s):
    print "YES"
else:
    print "NO"