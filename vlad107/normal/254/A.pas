var
  a1,a2,g,pred,last:array[0..1111111]of longint;
  kg,ka,ii,x,i,n:longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  n:=2*n;
  for i:=1 to n do begin
    read(x);
    inc(kg);g[kg]:=i;pred[kg]:=last[x];last[x]:=kg;
  end;
  for i:=1 to 5000 do begin
    ii:=last[i];
    while (ii>0)do begin
      if (pred[ii]=0)then begin
        writeln(-1);
        exit;
      end;
      inc(ka);
      a1[ka]:=g[ii];
      ii:=pred[ii];
      a2[ka]:=g[ii];
      ii:=pred[ii];
    end;
  end;
  for i:=1 to ka do writeln(a1[i],' ',a2[i]);
end.