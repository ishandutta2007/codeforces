input()
for i in map(int,raw_input().split()):
	print i*[4,2,4,1][i%4]+1