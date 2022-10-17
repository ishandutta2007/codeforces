input()
s=raw_input().split()
print sum([s.count(i)/2 for i in set(s)])/2