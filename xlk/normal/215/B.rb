a=gets.split.map(&:to_i)[1..-1].max;
b=gets.split.map(&:to_i)[1..-1].max;
c=gets.split.map(&:to_i)[1..-1].min;
d,e=gets.split.map &:to_f;
p (a*a*b*e/(c*d+b*e))**0.5