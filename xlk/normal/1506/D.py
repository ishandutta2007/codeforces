from collections import *
for _ in range(input()):
	n=input()
	print max(max(Counter(raw_input().split()).values())*2-n,n%2)