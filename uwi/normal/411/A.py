s = raw_input().strip()
import string
if len(s) >= 5 and any(c in string.uppercase for c in s) and any(c in string.lowercase for c in s) and any(c in string.digits for c in s):
	print "Correct"
else:
	print "Too weak"