n=input()
s=raw_input().split()
print max(s.count(i)for i in s),len(set(s))