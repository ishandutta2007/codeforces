input()
a = map(int, raw_input().split())
for i in a:
	print sorted(a)[sorted(a).index(i)-1],