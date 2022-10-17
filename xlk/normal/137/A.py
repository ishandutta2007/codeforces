s=raw_input()
print sum([(len(x)+4)/5 for x in s.split('C')+s.split('P')])