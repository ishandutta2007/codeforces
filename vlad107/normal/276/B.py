s=raw_input()
T=sum(s.count(chr(i+97))%2 for i in range(26))
print ["Second","First"][(T%2)|(T<2)]