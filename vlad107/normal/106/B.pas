{$r-,q-,s-,i-,o+}
var
  old:array[0..500500]of boolean;
  n,i,j,min,nom:longint;
  a,b,c,d:array[0..500500]of longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i],b[i],c[i],d[i]);
  fillchar(old,sizeof(old),false);
  for i:=1 to n do 
    for j:=1 to n do 
      if (a[i]<a[j])and(b[i]<b[j])and(c[i]<c[j])then begin
        old[i]:=true;
        break;
      end;
  min:=1000000000;
  nom:=0;
  for i:=1 to n do 
    if (not old[i])and(d[i]<min)then begin
      min:=d[i];
      nom:=i;
    end;
  writeln(nom);
  close(output);close(input);
end.