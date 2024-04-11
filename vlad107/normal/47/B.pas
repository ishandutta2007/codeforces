var
  abc,s:string;
  a:array[1..100] of string;
  q,j,k,i,x,y:longint;
  tmp:char;
  ok:boolean;

begin
  for i:=1 to 3 do readln(a[i]);
  abc:='ABC';
  for q:=1 to 3 do for j:=1 to 3 do for k:=1 to 3 do 
    if (q<>j)and(q<>k)and(j<>k)then begin
      s:=abc[q]+abc[j]+abc[k];
      ok:=true;
      for i:=1 to 3 do begin
        x:=pos(a[i][1],s);y:=pos(a[i][3],s);
        if (a[i][2]='<')and(x>y)then begin
          ok:=false;break;
        end; 
        if (a[i][2]='>')and(x<y)then begin
          ok:=false;break;
        end;
      end;
      if (ok)then begin
        writeln(s);
        exit;
      end;
    end;
  writeln('Impossible');
end.