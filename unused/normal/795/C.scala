object Main extends App {
    var n = readInt
    if (n % 2 == 1) {
        print("7")
        n = n - 3
    }
    while (n >= 2) {
        print("1")
        n = n - 2
    }
    println("")
}