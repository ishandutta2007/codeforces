{$r-,q-,s-,i-,o+}
var
  i,j,k,res:longint;
  s:array[1..4]of string;
  ch:char;
  t,x:string;
  z:array[1..310000] of longint;

  function solve(s,q:string):string;
   var
     i,p,lt:longint;

   begin
     t:=q+'$'+s;
     p:=0;
     lt:=length(t);
     z[lt]:=0;
     for i:=2 to lt do begin
       while (p>0)and(t[lt-p]<>t[lt-i+1])do p:=z[p];
       if (t[lt-p]=t[lt-i+1])then inc(p);
       z[i]:=p;
       if (p=length(s))then begin
         if (length(s)>length(q))
           then solve:=s
           else solve:=q;
         exit;
       end;
     end;
     for i:=p+1 to length(q) do s:=s+q[i];
     solve:=s;
   end;

begin
  res:=trunc(1e9);
  for i:=1 to 3 do readln(s[i]);
  for i:=1 to 3 do for j:=1 to 3 do for k:=1 to 3 do
    if (i<>j) and (i<>k) and (j<>k) then begin
      x:=solve(s[i],s[j]);
      if (length(x)>=res)then break;
      x:=solve(x,s[k]);
      if (length(x)<res)then res:=lengtH(x);
      break;
    end;
  writeln(res);
end.