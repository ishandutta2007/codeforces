n=input()
s=raw_input()
print n-max(s.count(str(i))for i in[1,2,3])