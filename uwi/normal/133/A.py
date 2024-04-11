import sys
import re

line = sys.stdin.readline()

if re.search("[HQ9]", line):
	print "YES"
else:
	print "NO"