s = raw_input()
ln = len(s.split('-'))-1
sn = len(s.split('o'))-1
if sn == 0 or ln%sn == 0:
	print "YES"
else:
	print "NO"