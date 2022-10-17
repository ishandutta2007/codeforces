k=input()
l=input()
c=0
while k**c<l:c+=1
print "NO"if k**c>l else "YES\n%d"%(c-1)