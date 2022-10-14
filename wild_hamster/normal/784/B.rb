x=gets.to_i
b=x==0?1:0
while x>0
b+=(76943617>>x%16*2)%4
x/=16
end
p b