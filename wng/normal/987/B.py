a,b=[int(k) for k in raw_input().split(" ")]

if (b==2 and a==4) or (b==4 and a==2) or (a==b):
	print "="
elif (b==2 and a==3):
	print ">"
elif (b==3 and a==2):
	print "<"
elif a==1:
	print "<"
elif b==1:
	print ">"
elif a<b:
	print ">"
else:
	print "<"