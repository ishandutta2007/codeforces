s=raw_input()
if s=='1'+'0'*(len(s)-1):
	print len(s)-1
else:
	print len(s)+s[:s.rfind('1')].count('0')+1