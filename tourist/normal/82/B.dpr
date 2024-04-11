{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  kt,n,i,j,kg,x,k: longint;
  ok: boolean;
  ka,t: array [0..410] of longint;
  a: array [0..410,0..410] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(ka,sizeof(ka),0);
  for i:=1 to n*(n-1) div 2 do
  begin
    read(kg);
    if n = 2 then
    begin
      read(x);
      writeln(1,' ',x);
      write(kg-1);
      for j:=2 to kg do
      begin
        read(x);
        write(' ',x);
      end;
      writeln;
      halt;
    end;
    for j:=1 to kg do
    begin
      read(x);
      inc(ka[x]);
      a[x,ka[x]]:=i;
    end;
  end;
  for i:=1 to 200 do
    if ka[i] > 0 then
    begin
      kt:=1;
      t[1]:=i;
      for j:=i+1 to 200 do
        if ka[i] = ka[j] then
        begin
          ok:=True;
          for k:=1 to ka[i] do
            if a[i,k] <> a[j,k] then
            begin
              ok:=False;
              break;
            end;
          if ok then
          begin
            inc(kt);
            t[kt]:=j;
            ka[j]:=0;
          end;
        end;
      write(kt);
      for j:=1 to kt do write(' ',t[j]);
      writeln;
      ka[i]:=0;
    end;
  close(input);
  close(output);
end.